Param(
   [string]$CoverageTool
)

[string] $TestCoverageTool = "C:\Program Files (x86)\Microsoft Visual Studio\2017\TestAgent\Team Tools\Dynamic Code Coverage Tools\CodeCoverage.exe"
[string] $VSCoverageTool   = "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Team Tools\Dynamic Code Coverage Tools\CodeCoverage.exe"

if ([string]::IsNullOrWhiteSpace($CoverageTool)) {
    $CoverageTool = $TestCoverageTool
}

if(!(Test-Path $CoverageTool)) {
    if((Test-Path $VSCoverageTool)) {
        $CoverageTool = $VSCoverageTool
            
    } else {
        Throw [System.IO.FileNotFoundException] "CodeCoverage.exe not found at $TestCoverageTool or $VSCoverageTool"
    }
}

[string] $mypath = Get-Location
$Dir = get-childitem $mypath -recurse 
$List = $Dir | where {$_.extension -eq ".coverage"} |Get-Unique 

if ($List -eq $null) {
  Write-Output  "Cannot find a '.coverage' file using path '$mypath'"
} else {
  [string] $FileName = "$mypath\MSCoverage.xml"
  if (Test-Path $FileName) {
    Remove-Item $FileName
  }    
  Write-Output "Create $FileName"
  & "$CoverageTool" analyze /output:MSCoverage.xml $List.FullName
}

#foreach($projectFile in $projectFiles)
#{
#    $project=$projectFile.Directory.Name

#    $buildCommands=$buildCommands+$projectFile.Directory.FullName
#    $testPoject = //Path//To//Test//Projects
#    if(Test-Path $testPoject)
#    {
#        _Verbose "$testPoject exists for $project"
#        $testCommand = "$OpenCoverUtil -register:user ""-excludebyfile:*\*.gen.cs"" ""-target:$DnxPath\dnx.exe "" ""-targetargs: $testPoject\project.json test"" ""-output:$Outpath\CS\$project.coverage.xml"" -skipautoprops -returntargetcode -filter:""+[$project*]*"""
#        _Verbose $testCommand
#        $testCommands=$testCommands+$testCommand
#    }
#}
