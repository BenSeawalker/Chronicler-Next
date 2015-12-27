QT += widgets

HEADERS	    =   mainwindow.h \
		diagramitem.h \
		diagramscene.h \
		arrow.h \
		diagramtextitem.h \
    cbubble.h \
    cstorybubble.h \
    ctextitem.h \
    propstorybubble.h \
    ctextedit.h \
    cstoryproperties.h \
    cpropertiesview.h \
    cactionbubble.h
SOURCES	    =   mainwindow.cpp \
		diagramitem.cpp \
		main.cpp \
		arrow.cpp \
		diagramtextitem.cpp \
		diagramscene.cpp \
    cbubble.cpp \
    cstorybubble.cpp \
    ctextitem.cpp \
    propstorybubble.cpp \
    ctextedit.cpp \
    cstoryproperties.cpp \
    cpropertiesview.cpp \
    cactionbubble.cpp
RESOURCES   =	chroniclernext.qrc


# install
TARGET = Chronicler-Next

FORMS += \
    cstoryproperties.ui
