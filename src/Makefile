#
# add your files to the _SRC lines. other lines shoudl remain untouched
#

CCC = g++
CCFLAGS = -Werror -pedantic -Wall -Wextra -Wvla -std=c++17
LIBS = -lglut -lGL #-lglu32 -lfreeglut -lopengl32
PMS_SRC = pms.cpp pms_class.cpp # add more files here (management)
PMS = pms
IPA_SRC = ipa.cpp Figure.cpp parking_area_draw.cpp parking_lot.cpp Vehicle.cpp # add more files here (interstellar)
IPA = ipa

#
# do not modify anything below
#

.PHONY: clean

all: pms ipa

pms: 
	$(CCC) $(CCFLAGS) -o $(PMS) $(PMS_SRC) $(LIBS)

ipa:
	$(CCC) $(CCFLAGS) -o $(IPA) $(IPA_SRC) $(LIBS)

clean: 
	$(RM) *.o *.a *~ $(PMS) $(IPA)
