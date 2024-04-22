/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "Tests.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "Tests.cpp", 6, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testCreateIPv4Address : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCreateIPv4Address() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "testCreateIPv4Address" ) {}
 void runTest() { suite_MyTestSuite.testCreateIPv4Address(); }
} testDescription_suite_MyTestSuite_testCreateIPv4Address;

static class TestDescription_suite_MyTestSuite_testCreateTCPIpv4Socket : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testCreateTCPIpv4Socket() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "testCreateTCPIpv4Socket" ) {}
 void runTest() { suite_MyTestSuite.testCreateTCPIpv4Socket(); }
} testDescription_suite_MyTestSuite_testCreateTCPIpv4Socket;

static class TestDescription_suite_MyTestSuite_testAcceptIncomingConnection : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAcceptIncomingConnection() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 22, "testAcceptIncomingConnection" ) {}
 void runTest() { suite_MyTestSuite.testAcceptIncomingConnection(); }
} testDescription_suite_MyTestSuite_testAcceptIncomingConnection;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
