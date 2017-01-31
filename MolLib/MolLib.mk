##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MolLib
ConfigurationName      :=Debug
WorkspacePath          :=/home/belarm/Documents/OBForceField
ProjectPath            :=/home/belarm/Documents/OBForceField/MolLib
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=belarm
Date                   :=11/03/16
CodeLitePath           :=/home/belarm/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="MolLib.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Residue.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protein.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/belarm/Documents/OBForceField/.build-debug"
	@echo rebuilt > "/home/belarm/Documents/OBForceField/.build-debug/MolLib"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Residue.cpp$(ObjectSuffix): Residue.cpp $(IntermediateDirectory)/Residue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/belarm/Documents/OBForceField/MolLib/Residue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Residue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Residue.cpp$(DependSuffix): Residue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Residue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Residue.cpp$(DependSuffix) -MM Residue.cpp

$(IntermediateDirectory)/Residue.cpp$(PreprocessSuffix): Residue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Residue.cpp$(PreprocessSuffix)Residue.cpp

$(IntermediateDirectory)/Protein.cpp$(ObjectSuffix): Protein.cpp $(IntermediateDirectory)/Protein.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/belarm/Documents/OBForceField/MolLib/Protein.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protein.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protein.cpp$(DependSuffix): Protein.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protein.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protein.cpp$(DependSuffix) -MM Protein.cpp

$(IntermediateDirectory)/Protein.cpp$(PreprocessSuffix): Protein.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protein.cpp$(PreprocessSuffix)Protein.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


