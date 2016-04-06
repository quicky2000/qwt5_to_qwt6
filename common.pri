unix{
  macx{ #MacOSX
    # To be done
  }else{ #Linux
    MY_LIB_PATH += -L$$MY_PATH/lib -L/usr/lib -L/usr/lib/x86_64-linux-gnu/ $$MY_QWT_LIB_PATH
    MY_INCLUDE_PATH += /usr/include/qt4/QtCore /usr/include/qt4/QtGui /usr/include/qt4 /usr/include/GL $$MY_QWT_INCLUDE_PATH
  }
}
win32{ #Windows
  #Note just stick the *.dll files in the executables directory to run
}

TEMPLATE = app
CONFIG -= debug
CONFIG += release
CONFIG += warn_on
LANGUAGE = C++

DEPENDPATH += . src include
INCLUDEPATH += . include 

# Input
HEADERS += include/main_window.h \
           include/slider_widget.h
SOURCES += src/main.cpp \
           src/main_window.cpp \
           src/slider_widget.cpp

DEPENDPATH += . src include
INCLUDEPATH += . include 


unix{
  debug {
    OBJECTS_DIR=.debug_obj_$$TARGET
    MOC_DIR=.debug_moc_$$TARGET
  }
  release {
    OBJECTS_DIR=.obj_$$TARGET
    MOC_DIR=.moc_$$TARGET
  }
  macx{
  }
  else{ #linux

    DEFINES += LINUX
    INCLUDEPATH += $$MY_INCLUDE_PATH
    LIBS += $$MY_LIB_PATH -l$$QWT_LIB_NAME -lGLU
    CONFIG += warn_off
    QMAKE_CXXFLAGS += -Wall -Wno-non-virtual-dtor -std=c++11
    QMAKE_CXXFLAGS -= -g
    profile {
      QMAKE_CXXFLAGS += -pg
      QMAKE_LFLAGS += -pg
    }
  }
}
win32{
}
debug{
  DEFINES += MYDEBUG
}

