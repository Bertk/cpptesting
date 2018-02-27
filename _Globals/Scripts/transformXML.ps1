PARAM
(
    [Parameter(Mandatory = $true)]
    [ValidateNotNullOrEmpty()]
    [String]$XmlPath,
     
    [Parameter(Mandatory = $true)]
    [ValidateNotNullOrEmpty()]
    [String]$XslPath,
     
    [Parameter(Mandatory = $true)]
    [ValidateNotNullOrEmpty()]
    [String]$HtmlOutput
)
 
try
{
    $XslPatht = New-Object System.Xml.Xsl.XslCompiledTransform
    $XslPatht.Load($XslPath)
    $XslPatht.Transform($XmlPath, $HtmlOutput)
     
    Write-Host "Generated output is on path: $HtmlOutput"
}
catch
{
    Write-Host $_.Exception -ForegroundColor Red
}
