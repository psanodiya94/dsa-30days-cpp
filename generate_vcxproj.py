#!/usr/bin/env python3
"""
Generate Visual Studio project files for all Day solutions
"""

import os

# Template for Day solution vcxproj file
VCXPROJ_TEMPLATE = '''<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|x64">
      <Configuration>Debug</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|x64">
      <Configuration>Release</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <VCProjectVersion>17.0</VCProjectVersion>
    <ProjectGuid>{{{guid}}}</ProjectGuid>
    <Keyword>Win32Proj</Keyword>
    <RootNamespace>Day{day_num}</RootNamespace>
    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <PlatformToolset>v143</PlatformToolset>
    <WholeProgramOptimization>true</WholeProgramOptimization>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings">
  </ImportGroup>
  <ImportGroup Label="Shared">
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <LinkIncremental>true</LinkIncremental>
    <OutDir>$(SolutionDir)bin\$(Configuration)\</OutDir>
    <IntDir>$(SolutionDir)obj\$(Configuration)\$(ProjectName)\</IntDir>
    <TargetName>Day{day_num}</TargetName>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <LinkIncremental>false</LinkIncremental>
    <OutDir>$(SolutionDir)bin\$(Configuration)\</OutDir>
    <IntDir>$(SolutionDir)obj\$(Configuration)\$(ProjectName)\</IntDir>
    <TargetName>Day{day_num}</TargetName>
  </PropertyGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <ClCompile>
      <PrecompiledHeader>NotUsing</PrecompiledHeader>
      <WarningLevel>Level4</WarningLevel>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>_DEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
      <LanguageStandard>stdcpp17</LanguageStandard>
      <AdditionalIncludeDirectories>$(SolutionDir);$(SolutionDir)src;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <ClCompile>
      <PrecompiledHeader>NotUsing</PrecompiledHeader>
      <WarningLevel>Level4</WarningLevel>
      <FunctionLevelLinking>true</FunctionLevelLinking>
      <IntrinsicFunctions>true</IntrinsicFunctions>
      <SDLCheck>true</SDLCheck>
      <PreprocessorDefinitions>NDEBUG;_CONSOLE;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <ConformanceMode>true</ConformanceMode>
      <LanguageStandard>stdcpp17</LanguageStandard>
      <AdditionalIncludeDirectories>$(SolutionDir);$(SolutionDir)src;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <GenerateDebugInformation>true</GenerateDebugInformation>
    </Link>
  </ItemDefinitionGroup>
  <ItemGroup>
    <ClCompile Include="solution.cpp" />
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>'''

# Template for filters file
FILTERS_TEMPLATE = '''<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="Source Files">
      <UniqueIdentifier>{{4FC737F1-C7A5-4376-A066-2A32D752A2FF}}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="solution.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
  </ItemGroup>
</Project>'''

def main():
    # Generate project files for each day
    for day in range(1, 31):
        day_num = f"{day:02d}"
        day_dir = f"src/Day{day_num}"

        # Check if directory exists
        if not os.path.exists(day_dir):
            print(f"Warning: {day_dir} does not exist, skipping...")
            continue

        # Generate GUID (use consistent format based on day number)
        guid = f"D1000000-0000-0000-0000-0000000000{day_num}"

        # Create vcxproj file
        vcxproj_content = VCXPROJ_TEMPLATE.format(
            day_num=day_num,
            guid=guid
        )

        vcxproj_path = os.path.join(day_dir, f"Day{day_num}.vcxproj")
        with open(vcxproj_path, 'w', encoding='utf-8') as f:
            f.write(vcxproj_content)
        print(f"Created {vcxproj_path}")

        # Create filters file
        filters_path = os.path.join(day_dir, f"Day{day_num}.vcxproj.filters")
        with open(filters_path, 'w', encoding='utf-8') as f:
            f.write(FILTERS_TEMPLATE)
        print(f"Created {filters_path}")

    print("\nAll project files generated successfully!")
    print("You can now open dsa-30days-cpp.sln in Visual Studio 2026")

if __name__ == "__main__":
    main()
