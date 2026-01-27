echo 'alias g++=/opt/homebrew/bin/g++-15' >> ~/.zshrc
source ~/.zshrc
g++ hlo1.cpp -o hlo1
./hlo1 < input.txt > output.txt