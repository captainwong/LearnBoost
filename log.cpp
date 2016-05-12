class LogFunction {
private:
	const char* _func_name;
	std::chrono::system_clock::time_point _begin;
public:
	LogFunction(const char* func_name) : _func_name(func_name) {
		JLOGA("%s in\n", _func_name); _begin = std::chrono::system_clock::now();
	}
	~LogFunction() { 
		auto diff = std::chrono::system_clock::now() - _begin;
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
		JLOGA("%s out, duration: %d(ms)\n", _func_name, msec.count()); 
	}
};

#define LOG_FUNCTION(func_name) LogFunction _log_function_object(func_name);
#define AUTO_LOG_FUNCTION LOG_FUNCTION(__FUNCTION__)
