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
    ctextedit.h
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
    ctextedit.cpp
RESOURCES   =	chroniclernext.qrc


# install
TARGET = Chronicler-Next

FORMS += \
    propstorybubble.ui
