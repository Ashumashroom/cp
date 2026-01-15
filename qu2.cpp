unalias g++ 2>/dev/null
echo 'alias g++=/opt/homebrew/bin/g++-15' >> ~/.zshrc
source ~/.zshrc
 g++ hlo1.cpp
./hlo1 < input.txt > output.txt