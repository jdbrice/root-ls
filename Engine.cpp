

// RooBarb
#include "XmlConfig.h"
#include "TaskEngine.h"
using namespace jdb;

// STL
#include <iostream>
#include <exception>


#include "root-ls/root-ls.h"

#define LOGURU_IMPLEMENTATION 1
#include "vendor/loguru.h"

int main( int argc, char* argv[] ) {
	// loguru::add_file("everything.log", loguru::Truncate, loguru::Verbosity_MAX);

	loguru::g_stderr_verbosity = 0;

	// cout << "args: ";
	// for ( int i = 0; i < argc; i++ ){
	// 	cout << "argv[" << i << "] = "<< quote( argv[i] ) << endl;
	// }   
	

	TaskFactory::registerTaskRunner<RootLS>( "RootLS" );

	TaskEngine engine( argc, argv, "RootLS" );
	
	engine.runTasks();

	return 0;
}
