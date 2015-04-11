## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_PREFIX=\""$(prefix)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project_notepad

project_notepad_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h

project_notepad_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

