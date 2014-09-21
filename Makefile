

Toddmoments = $(MINTROOT)/src/Users/mcoombes/Toddmoments
#include ../../Makefile.arch
include $(Toddmoments)/Makefile.arch

HdrSuf = h
SrcSuf = cpp
#MintDir = $(MINTROOT)/src/Mint
#MojitoDir = $(MINTROOT)/src/Mojito
BOOST = $(BOOSTROOT2)
#D2HHHHDir = $(D2HHHHROOT)
#BOOST = $(BOOSTROOT2)
#B2DX_HHHH = $(B2DX_HHHHROOT)


#include $(Toddmoments)/Makefile.arch

#LIBS += -lMatrix -lMathCore -lMathMore
#LIBS += -lHist -lTreePlayer -lGraf -lGraf3d -lGpad
#LIBS +=  -lCintex


#MOREINCS := $(wildcard $(MintDir)/*/src)
#MOREINCS += $(wildcard $(D2HHHHDir))
#MOREINCS += $(wildcard $(B2DX_HHHH))
#MOREINCS += $(wildcard $(MojitoDir)/*/src)
#MOREINCS += $(wildcard $(MintDir)/../..)
MOREINCS := $(wildcard $(BOOST))
MOREINCS += $(wildcard $(BOOST)/include/*)
#MOREINCS += $(wildcard $(Toddmoments))


#MOREINCSFLAGS := $(patsubst %,-I%,$(MOREINCS))
#CXXFLAGS += $(MOREINCSFLAGS)

#LIBS += -lMinuit
#LIBS += -lRooFit -lRooFitCore -lHtml -lRooStats 

#LIBS += -lprofiler

PROG = $(shell grep -l main *.cpp | sed 's/\.cpp//g')

#SRCS := $(wildcard $(MintDir)/*/src/*.$(SrcSuf))
#SRCS += $(wildcard $(MojitoDir)/*/src/*.$(SrcSuf))
SRCS := $(wildcard *.$(SrcSuf))
#SRCS += $(wildcard $(D2HHHHDir)/src/D0DeltaMFit/*.$(SrcSuf))
#SRCS += $(wildcard $(D2HHHHDir)/src/DeltaMassFit/*.$(SrcSuf))
#SRCS += $(wildcard $(D2HHHHDir)/src/DmassFit/*.$(SrcSuf))
#SRCS += $(wildcard $(D2HHHHDir)/src/Utils/*.$(SrcSuf))
#SRCS += $(wildcard $(B2DX_HHHH)/src/MassFitter/src/*.$(SrcSuf))
#SRCS += $(wildcard $(B2DX_HHHH)/src/Utils/src/*.$(SrcSuf))
#SRCS += $(wildcard $(B2DX_HHHH)/src/Exceptions/src/*.$(SrcSuf))
#SRCS += $(wildcard $(Toddmoments)/src/*.$(SrcSuf))


#HDRS := $(wildcard $(MintDir)/*/src/*.$(HdrSuf))
#HDRS += $(wildcard $(MintDir)/../../Mint/*.$(HdrSuf))
#HDRS += $(wildcard $(MojitoDir)/*/src/*.$(HdrSuf))
HDRS := $(wildcard *.$(HdrSuf))
#HDRS += $(wildcard $(D2HHHHDir)/D2HHHH/*.$(HdrSuf))
#HDRS += $(wildcard $(B2DX_HHHH)/*/*.$(HdrSuf))
#HDRS += $(wildcard $(Toddmoments)/Toddmoments/*.$(HdrSuf))

#HDRS += $(wildcard $(Bu2D0H_ROOT)/*/*.h)

#BOOST

HDRS += $(wildcard $(BOOST)/*/*.$(HdrSuf))
HDRS += $(wildcard $(BOOST)/*/*.hpp)
HDRS += $(wildcard $(BOOST)/*/*/*/*.hpp)




OBJS := $(patsubst %.$(SrcSuf),%.$(ObjSuf),$(SRCS))
##OBJS := $(shell echo $(OBJS) | sed 's/\/src\//\/bin\//g')
SRCSLOCAL += $(wildcard *.$(SrcSuf))
OBJSLOCAL := $(patsubst %.$(SrcSuf),%.$(ObjSuf),$(SRCSLOCAL))

# top-level rule, to compile everything.
all: $(PROG)
	@echo ""; echo " ============== make all done ==============="; echo ""

# don't link, just compile
src: $(OBJSLOCAL)
	@echo ""; echo " ============== make src done ==============="; echo ""

depend: .depend
	@echo ""; echo " ============== make depend done ============"; echo ""

.depend: $(SRCS) $(HDRS)
	@echo ""; echo " ===== Figuring out dependencies ============"; echo ""
	@makedepend -f- -- $(CXXFLAGS) -- $(SRCS) > .depend 2> .makedepend.err
	@echo ""; echo " result in .depend, errors in .makedepend.err"; echo ""
	@echo ""; echo " ======== Dependencies done. ================"; echo ""

clean: 
	$(RM) $(OBJS) $(PROG) .depend .makedepend.err
	@echo ""; echo " =============== make clean done ============"; echo ""

debug:
	@echo "sources " $(SRCS)
	@echo "objects " $(OBJS)
	@echo "pwd " $(PWD)
	@echo "CXXFLAGS " $(CXXFLAGS)
	@echo "MintDir " $(MintDir)
$(PROG): $(OBJS)
	@echo ""; echo " =============== linking ===================="; echo ""
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $(PROG)
	@echo ""; echo " =============== linking done ==============="; echo ""

#include .depend

%.(ObjSuf): %.$(SrcSuf)
	$(CXX) $(CXXFLAGS) -c $<
##
# DO NOT DELETE
