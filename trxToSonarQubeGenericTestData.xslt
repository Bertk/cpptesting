<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="3.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:b="http://microsoft.com/schemas/VisualStudio/TeamTest/2010">
  <xsl:param name="solutionFolder" />
  <xsl:param name="projectName" />


  <xsl:output method="xml" indent="yes" />
  <xsl:template match="/">
    <testExecutions version="1">
      <xsl:for-each-group select="//b:TestMethod" group-by="@className">
        <xsl:variable name="a" select="replace(current-grouping-key(), $projectName, '')" />
        <xsl:variable name="b" select="replace($a, '\.', '\\')" />
        <xsl:variable name="c" select="concat($solutionFolder, '\', $projectName, $b, '.cpp')" />
        <file path="{$c}">
          <xsl:for-each select="//b:TestMethod[@className=current-grouping-key()]/preceding-sibling::*[1]">
            <xsl:variable name="currentExecutionId" select="@id"/>
            <xsl:variable name="testName" select="parent::*/@name"/>
            <xsl:apply-templates select="//b:UnitTestResult[@executionId=$currentExecutionId]"/>
          </xsl:for-each>
        </file>
      </xsl:for-each-group>
    </testExecutions>
  </xsl:template>

  <xsl:template match="b:UnitTestResult">
    <xsl:variable name="duration_seconds" select="substring(@duration, 7)"/>
    <xsl:variable name="duration_ms" select="round(100 * number($duration_seconds))"/>
    <xsl:variable name="testId" select="@testId"/>

    <testCase name="{@testName}" duration="{$duration_ms}">
      <xsl:apply-templates select="//b:UnitTest[@id=$testId]">
        <xsl:with-param name="outcome" select="@outcome"/>
        <xsl:with-param name="message" select="b:Output/b:ErrorInfo/b:Message"/>
        <xsl:with-param name="stacktrace" select="b:Output/b:ErrorInfo/b:StackTrace"/>
      </xsl:apply-templates>
    </testCase>
  </xsl:template>

  <xsl:template match="b:UnitTest">
    <xsl:param name="outcome" />
    <xsl:param name="message" />
    <xsl:param name="stacktrace" />
    <xsl:if test="contains($outcome, 'Failed')">
      <failure message="{$message}">
        <xsl:value-of select="$stacktrace" />
      </failure>
    </xsl:if>

    <xsl:if test="contains($outcome, 'NotExecuted')">
      <skipped message="Skipped">Skipped</skipped>
    </xsl:if>
  </xsl:template>
</xsl:stylesheet>
