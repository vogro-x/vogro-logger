filepolicy: filepolicy_test.cpp ../policy.hpp
	g++ -std=c++11 filepolicy_test.cpp ../policy.hpp -o filepolicy
	./filepolicy

terminalpolicy: terminalpolicy_test.cpp ../policy.hpp
	g++ -std=c++11 terminalpolicy_test.cpp ../policy.hpp -o terminalpolicy
	./terminalpolicy

logger: logger_test.cpp ../policy.hpp ../logger.hpp
	g++ -std=c++11 logger_test.cpp ../policy.hpp ../logger.hpp -o logger
	./logger
	

clean:
	rm a.out *.gch filepolicy *.log terminalpolicy policy
	
