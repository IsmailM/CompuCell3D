@ECHO OFF
@SET PREFIX_CC3D=D:\Program Files (x86)\CA
@SET PYTHON_INSTALL_PATH=c:\Python27

@SET MAX_NUMBER_OF_CONSECUTIVE_RUNS=50

@SET PATH=%PREFIX_CC3D%\bin;%PATH%

@SET COMPUCELL3D_PLUGIN_PATH=%PREFIX_CC3D%\lib\CompuCell3DPlugins
@SET COMPUCELL3D_STEPPABLE_PATH=%PREFIX_CC3D%\lib\CompuCell3DSteppables
@SET SWIG_LIB_INSTALL_DIR=%PREFIX_CC3D%\lib\python
@SET PYTHON_MODULE_PATH=%PREFIX_CC3D%\pythonSetupScripts
@SET PYTHON_MODULE_EXTRA_PATH=%CD%
@SET PYTHON_DEPS_PATH=%PREFIX_CC3D%\lib\PythonDeps

@SET PYTHONPATH=%SWIG_LIB_INSTALL_DIR%;%PYTHONPATH%
@SET PYTHONPATH=%PREFIX_CC3D%;%PYTHONPATH%
@SET PYTHONPATH=%PREFIX_CC3D%/playerCA;%PYTHONPATH%


@SET VTKPATH=%PREFIX_CC3D%\bin

@SET PATH=%VTKPATH%;%PATH%
@SET PATH=%PREFIX_CC3D%\lib\extralibs;%PATH%
@SET PATH=%PYTHON_INSTALL_PATH%;%PATH%

@SET PATH=%COMPUCELL3D_PLUGIN_PATH%;%PATH%
@SET PATH=%COMPUCELL3D_STEPPABLE_PATH%;%PATH%

@SET SOSLIB_PATH=%PREFIX_CC3D%\examplesSoslib

@set CURRENT_DIRECTORY=%CD%


REM removing duplicates from PATH environment variable - this variable can get recusrive addodn with each subsequent run resulting in windows shell error - also a good idea to keep PATH short anyway
REM a bit ugly but works...
python "%PREFIX_CC3D%\pythonSetupScripts\envVarSanitizer.py" "PATH" >%TMP%\cc3dtmppathfile
@set /p PATH= < %TMP%\cc3dtmppathfile
@del %TMP%\cc3dtmppathfile

cd %PREFIX_CC3D%

@SET exit_code=0
python "%PREFIX_CC3D%\playerCA\caplayer.pyw" %* --currentDir="%CURRENT_DIRECTORY%"
@SET exit_code= %errorlevel%

goto simulationend

:simulationend
   echo "SIMULATION FINISHED"
   cd %CURRENT_DIRECTORY%

exit /b %exit_code%     