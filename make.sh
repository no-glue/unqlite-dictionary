g++ -Wall -W -fpermissive -std=c++11 unqlite_wrapper.cpp -o unqlite_wrapper -l unqlite
g++ -Wall -W -fpermissive -std=c++11 sample.cpp -o sample -l unqlite