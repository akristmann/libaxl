EXTRA_DIST = Makefile.win libaxl-babel.def # libaxl-babel.vcproj

if ENABLE_AXL_LOG
LOG = -DSHOW_DEBUG_LOG
endif

INCLUDES = $(compiler_options) -g -I../src -I$(top_srcdir)/src -I$(top_srcdir) $(LIBRARIES_CFLAGS) -DVERSION=\""$(AXL_VERSION)"\" \
	-DPACKAGE_DTD_DIR=\""$(datadir)"\" -DPACKAGE_TOP_DIR=\""$(top_srcdir)"\"  \
	-D__axl_disable_broken_bool_def__ \
	-DVERSION=\"$(AXL_VERSION)\" $(LOG)

libaxl_babelincludedir = $(includedir)/axl

lib_LTLIBRARIES = libaxl-babel.la

libaxl_babel_la_SOURCES     = \
	axl_babel.c \
	axl_babel_iso885915.c \
	axl_babel_iso88591.c \
	axl_babel_iso88592.c \
	axl_babel_iso88593.c \
	axl_babel_iso88594.c \
	axl_babel_iso88595.c \
	axl_babel_iso88596.c \
	axl_babel_iso88597.c \
	axl_babel_iso88598.c \
	axl_babel_iso88599.c

libaxl_babelinclude_HEADERS = \
	axl_babel.h \
	axl_babel_iso885915.h \
	axl_babel_iso88591.h \
	axl_babel_iso88592.h \
	axl_babel_iso88593.h \
	axl_babel_iso88594.h \
	axl_babel_iso88595.h \
	axl_babel_iso88596.h \
	axl_babel_iso88597.h \
	axl_babel_iso88598.h \
	axl_babel_iso88599.h

libaxl_babel_la_LIBADD  = $(top_builddir)/src/libaxl.la	

libaxl_babel_la_LDFLAGS = -no-undefined -export-symbols-regex '^(axl|__axl|_axl).*'

libaxl-babel.def: update-def

update-def:
	echo "EXPORTS" > libaxl-babel.def
	cat .libs/libaxl-babel.exp >> libaxl-babel.def

refresh-tables: gen-table
	./gen-table codes.txt iso885915.utf8.txt iso-8859-15
	./gen-table codes.txt iso88591.utf8.txt iso-8859-1
	./gen-table codes.txt iso88592.utf8.txt iso-8859-2
	./gen-table codes.txt iso88593.utf8.txt iso-8859-3
	./gen-table codes.txt iso88594.utf8.txt iso-8859-4
	./gen-table codes.txt iso88595.utf8.txt iso-8859-5
	./gen-table codes.txt iso88596.utf8.txt iso-8859-6
	./gen-table codes.txt iso88597.utf8.txt iso-8859-7
	./gen-table codes.txt iso88598.utf8.txt iso-8859-8
	./gen-table codes.txt iso88599.utf8.txt iso-8859-9


# replace with bin_PROGRAMS to check performance
noinst_PROGRAMS = gen-codes gen-table read-codes

gen_codes_SOURCES  = gen-codes.c
gen_codes_LDADD   = $(top_builddir)/src/libaxl.la 

gen_table_SOURCES  = gen-table.c
gen_table_LDADD   = $(top_builddir)/src/libaxl.la 

read_codes_SOURCES = read-codes.c
read_codes_LDADD   = $(top_builddir)/src/libaxl.la 


