QT += widgets

HEADERS	    =   mainwindow.h \
		diagramitem.h \
		diagramscene.h \
		arrow.h \
		diagramtextitem.h \
    cbubble.h \
    cstorybubble.h \
    ctextitem.h \
    ctextedit.h \
    cstoryproperties.h \
    cpropertiesview.h \
    cconditionbubble.h \
    cconditionproperties.h \
    clineedit.h \
    cchoicebubble.h \
    cchoice.h \
    clink.h
SOURCES	    =   mainwindow.cpp \
		diagramitem.cpp \
		main.cpp \
		arrow.cpp \
		diagramtextitem.cpp \
		diagramscene.cpp \
    cbubble.cpp \
    cstorybubble.cpp \
    ctextitem.cpp \
    ctextedit.cpp \
    cstoryproperties.cpp \
    cpropertiesview.cpp \
    cconditionbubble.cpp \
    cconditionproperties.cpp \
    clineedit.cpp \
    cchoicebubble.cpp \
    cchoice.cpp \
    clink.cpp
RESOURCES   =	chroniclernext.qrc


# install
TARGET = Chronicler-Next

FORMS +=
