g++ -Wall -W -fpermissive -std=c++11 -w unqlite_wrapper.cpp -o unqlite_wrapper -l unqlite
g++ -Wall -W -fpermissive -std=c++11 -w sample.cpp -o sample -l unqlite
g++ -Wall -W -fpermissive -std=c++11 -w helper_wrapper.cpp -o helper_wrapper -l unqlite
