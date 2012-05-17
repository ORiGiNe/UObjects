CC = g++
INCLUDES = -I $${URBI_ROOT}/include -I ../userspace-usb-serie/commun -I ../userspace-usb-serie/pc
CFLAGS = -shared -fPIC -DIAmNotOnThePandaBoard=0
TARGET = ULib.so
SOURCES = \
	../userspace-usb-serie/commun/*.cpp \
	../userspace-usb-serie/pc/*.cpp \
	UGaop.cpp \
    UCapteur.cpp \
	UEffecteur.cpp

default: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	urbi-launch --start $(TARGET) -- main.u

interactive: $(TARGET)
	urbi-launch --start $(TARGET) -- --interactive

clean:
	rm $(TARGET)
