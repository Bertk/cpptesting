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

#Write-Output  "$CoverageTool analyze /output:MSCoverage.xml $List.FullName"

& "$CoverageTool" analyze /output:MSCoverage.xml $List.FullName

