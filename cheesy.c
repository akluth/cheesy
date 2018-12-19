#include <vte/vte.h>

#define CLR_R(x)   (((x) & 0xff0000) >> 16)
#define CLR_G(x)   (((x) & 0x00ff00) >>  8)
#define CLR_B(x)   (((x) & 0x0000ff) >>  0)
#define CLR_16(x)  ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
                                    .green = CLR_16(CLR_G(x)), \
                                    .blue = CLR_16(CLR_B(x)), \
                                    .alpha = 0.0 }

int main(int argc, char *argv[])
{
    GtkWidget *window, *terminal;
    PangoFontDescription *pfd;

    /* Initialise GTK, the window and the terminal */
    gtk_init(&argc, &argv);
    terminal = vte_terminal_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    GdkScreen *screen;
    GdkVisual *visual;

    screen = gtk_widget_get_screen (GTK_WIDGET (window));
    visual = gdk_screen_get_rgba_visual (screen);

    if (gdk_screen_is_composited (screen) &&
        (visual = gdk_screen_get_rgba_visual (screen)) != NULL) {
        gtk_widget_set_visual (GTK_WIDGET (window), visual);
    } else {
        gtk_widget_set_visual (GTK_WIDGET (window), gdk_screen_get_system_visual (screen));
    }

    gtk_window_set_title(GTK_WINDOW(window), "cheesy");
    gtk_window_set_default_size(GTK_WINDOW(window), 900, 500);

    /* Start a new shell */
    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL};
    
    g_strfreev(envp);

    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT,
        NULL,       /* working directory  */
        command,    /* command */
        NULL,       /* environment */
        0,          /* spawn flags */
        NULL, NULL, /* child setup */
        NULL,       /* child pid */
        -1, NULL, NULL, NULL);

    pfd = pango_font_description_from_string("Source Code Pro Medium");
    vte_terminal_set_font(VTE_TERMINAL(terminal), pfd);

    vte_terminal_set_colors(
        VTE_TERMINAL(terminal),
        &CLR_GDK(0xffffff),
        &(GdkRGBA){ .alpha = 0.85 },
        (const GdkRGBA[]){
            CLR_GDK(0x111111),
            CLR_GDK(0xd36265),
            CLR_GDK(0xaece91),
            CLR_GDK(0xe7e18c),
            CLR_GDK(0x5297cf),
            CLR_GDK(0x963c59),
            CLR_GDK(0x5E7175),
            CLR_GDK(0xbebebe),
            CLR_GDK(0x666666),
            CLR_GDK(0xef8171),
            CLR_GDK(0xcfefb3),
            CLR_GDK(0xfff796),
            CLR_GDK(0x74b8ef),
            CLR_GDK(0xb85e7b),
            CLR_GDK(0xA3BABF),
            CLR_GDK(0xffffff)
    }, 16);

    /* Connect some signals */
    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
    g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);

    /* Put widgets together and run the main loop */
    gtk_container_add(GTK_CONTAINER(window), terminal);
    gtk_widget_show_all(window);
    gtk_main();
}
