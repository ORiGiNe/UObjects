CC = g++
INCLUDES = -I $${URBI_ROOT}/include -I ../userspace-usb-serie/commun -I ../userspace-usb-serie/pc
CFLAGS = -shared -fPIC -DIAmNotOnThePandaBoard=0
TARGET = ULib.so
SOURCES = \
	../userspace-usb-serie/commun/Peripherique.cpp \
	../userspace-usb-serie/commun/Commande.cpp \
	../userspace-usb-serie/pc/GaopProtocol.cpp \
	UGaop.cpp \
	../userspace-usb-serie/pc/Capteur.cpp \
    UCapteur.cpp \
	UEffecteur.cpp

default: target

target: $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	urbi-launch --start $(TARGET) -- main.u

interactive: $(TARGET)
	urbi-launch --start $(TARGET) -- --interactive

clean:
	rm $(TARGET)
