##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FromCoords
ConfigurationName      :=Debug
WorkspacePath          :=/home/belarm/Documents/OBForceField
ProjectPath            :=/home/belarm/Documents/OBForceField/FromCoords
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=belarm
Date                   :=11/02/16
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="FromCoords.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/openbabel-2.0 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)openbabel 
ArLibs                 :=  "openbabel" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall ~/lib/all.a $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_atom_types.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_include_mapped_vector.C$(ObjectSuffix) $(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/belarm/Documents/OBForceField/FromCoords/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)main.cpp

$(IntermediateDirectory)/src_atom_types.cpp$(ObjectSuffix): src/atom_types.cpp $(IntermediateDirectory)/src_atom_types.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/belarm/Documents/OBForceField/FromCoords/src/atom_types.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_atom_types.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_atom_types.cpp$(DependSuffix): src/atom_types.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_atom_types.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_atom_types.cpp$(DependSuffix) -MM src/atom_types.cpp

$(IntermediateDirectory)/src_atom_types.cpp$(PreprocessSuffix): src/atom_types.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_atom_types.cpp$(PreprocessSuffix)src/atom_types.cpp

$(IntermediateDirectory)/src_include_mapped_vector.C$(ObjectSuffix): src/include/mapped_vector.C $(IntermediateDirectory)/src_include_mapped_vector.C$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/belarm/Documents/OBForceField/FromCoords/src/include/mapped_vector.C" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_include_mapped_vector.C$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_include_mapped_vector.C$(DependSuffix): src/include/mapped_vector.C
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_include_mapped_vector.C$(ObjectSuffix) -MF$(IntermediateDirectory)/src_include_mapped_vector.C$(DependSuffix) -MM src/include/mapped_vector.C

$(IntermediateDirectory)/src_include_mapped_vector.C$(PreprocessSuffix): src/include/mapped_vector.C
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_include_mapped_vector.C$(PreprocessSuffix)src/include/mapped_vector.C

$(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(ObjectSuffix): src/include/mapped_ptr_vector.C $(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/belarm/Documents/OBForceField/FromCoords/src/include/mapped_ptr_vector.C" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(DependSuffix): src/include/mapped_ptr_vector.C
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(ObjectSuffix) -MF$(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(DependSuffix) -MM src/include/mapped_ptr_vector.C

$(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(PreprocessSuffix): src/include/mapped_ptr_vector.C
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_include_mapped_ptr_vector.C$(PreprocessSuffix)src/include/mapped_ptr_vector.C


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


