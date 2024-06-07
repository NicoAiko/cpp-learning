#include "Runner.h"

Runner::Runner() {
	LOG("Starting application...");
}

Runner::~Runner() {
	LOG("Finishing application...");
	LOG_DECONSTRUCT;
}