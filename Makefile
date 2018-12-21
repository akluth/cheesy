all: cheesy

cheesy:
	gcc -O2 -Wall -fPIE -fstack-protector -I/usr/include/vte-2.91 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/lib/libffi-3.2.1/include -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/gtk-3.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/harfbuzz -I/usr/include/uuid -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/gio-unix-2.0 -I/usr/include/libdrm -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -pthread -I/usr/include/p11-kit-1 cheesy.c -o cheesy -lvte-2.91 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lz -lpcre2-8 -lgnutls

install:
	cp cheesy /usr/local/bin/cheesy
	cp cheesy.png /usr/share/icons/hicolor/48x48/apps
	cp cheesy.desktop /usr/share/applications
	touch /usr/share/icons/hicolor
	gtk-update-icon-cache

clean:
	rm cheesy *.o 

.PHONY: all cheesy clean
