TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    main.cpp \
    ../SS_Bencoder/src/Bencoder.cpp \
    ../SS_Bencoder/src/Tokens.cpp \
    ../SS_Bencoder/tst/main.cpp \
    ../SS_Bencoder/tst/TestParse.cpp \
    ../SS_Logger/src/Logger.cpp \
    ../SS_Logger/tst/main.cpp \
    ../SS_Logger/tst/TestLogger.cpp \
    ../SS_Utils/src/StringUtils.cpp \
    ../SS_Utils/tst/main.cpp \
    ../SS_Utils/tst/TestStringUtils.cpp

DISTFILES += \
    ../TAGS \
    ../SS_Bencoder/tst/[nCore][xvid_hun]Green.Zone.2010.HUN.BDRip.XviD-HDEvo.torrent \
    ../SS_Bencoder/tst/archlinux-2018.09.01-x86_64.iso.torrent \
    ../etc/coverage_check.pl \
    ../etc/leak_check.pl \
    ../etc/usage \
    ../SS_Bencoder/etc/links \
    ../SS_Bencoder/tst/test.txt \
    ../SS_Bencoder/tst/test2.txt \
    ../SS_Logger/etc/help \
    ../etc/COPYING \
    ../etc/links \
    ../SS_Bencoder/tst/SConscript \
    ../SS_Bencoder/SConscript \
    ../SS_Bencoder/SConstruct \
    ../SS_Logger/tst/SConscript \
    ../SS_Logger/SConscript \
    ../SS_Logger/SConstruct \
    ../SS_Utils/tst/SConscript \
    ../SS_Utils/SConscript \
    ../SS_Utils/SConstruct \
    ../SConstruct

SUBDIRS += \
    qtproject.pro

HEADERS += \
    ../include/bencoder/Bencoder.hpp \
    ../include/bencoder/Tokens.hh \
    ../include/logger/Logger.hpp \
    ../include/utils/StringUtils.hpp \
    ../SS_Bencoder/include/bencoder/Bencoder.hpp \
    ../SS_Bencoder/include/bencoder/Tokens.hh \
    ../SS_Logger/include/logger/Logger.hpp \
    ../SS_Utils/include/utils/StringUtils.hpp
