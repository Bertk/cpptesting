Param(
   [string]$TestResults
)

[string] $mypath = Get-Location
$Dir = get-childitem "$mypath\TestResults" -recurse 
$List = $Dir | where {$_.extension -eq ".trx"} |Get-Unique 

if ($List -eq $null) {
  Write-Output  "Cannot find a '.trx' file using path '$mypath\TestResults'"
} else {
  [string] $FileName = "$mypath\MSTestResults.trx"
  if (Test-Path $FileName) {
    Remove-Item $FileName
  } 
  Write-Output "Create $FileName"
  Copy-Item $List.FullName $FileName
}

