AUTOMAKE_OPTIONS = foreign

INCLUDES = -I./ @OGG_CFLAGS@

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = vorbisidec.pc

lib_LTLIBRARIES = libvorbisidec.la

AM_CFLAGS=-Dvorbis_block_init=ivorbis_block_init -D_vorbis_block_alloc=_ivorbis_block_alloc -D_vorbis_block_ripcord=_ivorbis_block_ripcord -Dvorbis_block_clear=ivorbis_block_clear -Dvorbis_dsp_clear=ivorbis_dsp_clear -Dvorbis_synthesis=ivorbis_synthesis -Dvorbis_synthesis_restart=ivorbis_synthesis_restart -Dvorbis_synthesis_init=ivorbis_synthesis_init -Dvorbis_synthesis_blockin=ivorbis_synthesis_blockin -Dvorbis_synthesis_pcmout=ivorbis_synthesis_pcmout -Dvorbis_synthesis_read=ivorbis_synthesis_read -D_vorbis_apply_window=_ivorbis_apply_window -Dvorbis_comment_init=ivorbis_comment_init -Dvorbis_comment_query=ivorbis_comment_query -Dvorbis_comment_query_count=ivorbis_comment_query_count -Dvorbis_comment_clear=ivorbis_comment_clear -Dvorbis_info_blocksize=ivorbis_info_blocksize -Dvorbis_info_init=ivorbis_info_init -Dvorbis_info_clear=ivorbis_info_clear -Dvorbis_synthesis_idheader=ivorbis_synthesis_idheader -Dvorbis_synthesis_headerin=ivorbis_synthesis_headerin -Dvorbis_staticbook_unpack=ivorbis_staticbook_unpack -Dvorbis_book_decode=ivorbis_book_decode -Dvorbis_book_decodevs_add=ivorbis_book_decodevs_add -Dvorbis_book_decodev_add=ivorbis_book_decodev_add -Dvorbis_book_decodev_set=ivorbis_book_decodev_set -Dvorbis_book_decodevv_add=ivorbis_book_decodevv_add -D_ilog=_iilog -D_make_words=_imake_words -D_book_maptype1_quantvals=_ibook_maptype1_quantvals -D_book_unquantize=_ibook_unquantize -Dvorbis_staticbook_destroy=ivorbis_staticbook_destroy -Dvorbis_book_clear=ivorbis_book_clear -Dvorbis_book_init_decode=ivorbis_book_init_decode -Dmdct_backward=imdct_backward

libvorbisidec_la_SOURCES = mdct.c block.c window.c \
                        synthesis.c info.c \
                        floor1.c floor0.c vorbisfile.c \
                        res012.c mapping0.c registry.c codebook.c \
			sharedbook.c \
                        codebook.h misc.h mdct_lookup.h\
                        os.h mdct.h block.h ivorbisfile.h lsp_lookup.h\
                        registry.h window.h window_lookup.h\
                        codec_internal.h backends.h \
			asm_arm.h ivorbiscodec.h
libvorbisidec_la_LDFLAGS = -version-info @V_LIB_CURRENT@:@V_LIB_REVISION@:@V_LIB_AGE@
libvorbisidec_la_LIBADD = @OGG_LIBS@

EXTRA_PROGRAMS = ivorbisfile_example iseeking_example
CLEANFILES = $(EXTRA_PROGRAMS) $(lib_LTLIBRARIES)

ivorbisfile_example_SOURCES = ivorbisfile_example.c
ivorbisfile_example_LDFLAGS = -static 
ivorbisfile_example_LDADD = libvorbisidec.la @OGG_LIBS@

iseeking_example_SOURCES = iseeking_example.c
iseeking_example_LDFLAGS = -static 
iseeking_example_LDADD = libvorbisidec.la @OGG_LIBS@

includedir = $(prefix)/include/tremor

include_HEADERS = ivorbiscodec.h ivorbisfile.h config_types.h

EXTRA_DIST = vorbisidec.pc.in \
        $(srcdir)/doc/*.html $(srcdir)/win32/VS*/libtremor/*.vcproj

example:
	-ln -fs . vorbis
	$(MAKE) ivorbisfile_example
	$(MAKE) iseeking_example

debug:
	$(MAKE) all CFLAGS="@DEBUG@" 

profile:
	$(MAKE) all CFLAGS="@PROFILE@"
