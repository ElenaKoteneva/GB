//Koteneva Elena
//Homework 6

#include <iostream>
#include <fstream>
#include <cstring>

int main(){
	/*
	FILE* f1 = fopen("a.txt","w");
	FILE* f2 = fopen("b.txt","w");
	
	fprintf(f1,"Henry is an astronomer. He is very excited because he thinks he might have discovered the beginning of a new star. But then he gets even more exciting news ... he’s going to be a father!");
	
	fprintf(f2,"Nikos was an ordinary man. One thing that he did not believe in was superstition. But when so many things that are meant to cause bad luck started bringing him good luck, he began to wonder …");
	
	fclose(f1);
	fclose(f2);
	*/
	
	//Task 1
	
	char text1[] = {"Henry is an astronomer. He is very excited because he thinks he might have discovered the beginning of a new star. "};
	char text2[] = {"Nikos was an ordinary man. One thing that he did not believe in was superstition. "};
	
	std::ofstream f1("a.txt");
	std::ofstream f2("b.txt");
	
	f1.write(text1,sizeof(text1));
	f2.write(text2,sizeof(text2));
	
	f1.close();
	f2.close();

	//Task 2
		
	std::ifstream a("a.txt");
	std::ifstream b("b.txt");
	
	a.seekg(0,std::ios_base::end);
	b.seekg(0,std::ios_base::end);
	size_t size_a = a.tellg();
	size_t size_b = b.tellg();
		
	a.seekg(0,std::ios::beg);
	b.seekg(0,std::ios::beg);
	
	if (!a) std::cout << "File a.txt not found!\n";
	if (!b) std::cout << "File b.txt not found!\n";
	
	char* buffer = new char[size_a+size_b];
	
	a.read(buffer,(size_a));
	b.read((buffer+size_a),(size_b));
	
	if (!a) std::cout << "Error reading file a.txt!\n";
	if (!b) std::cout << "Error reading file b.txt!\n";
		
	std::ofstream fout("out.txt");
	fout.write(buffer,(size_a+size_b));
	
	a.close();
	b.close();
	fout.close();
	delete[] buffer;
	
	//Task 3
	
	const char* word;
	word = "he";
	char symbol;
	size_t index = 0;
	
	std::ifstream fin("a.txt");
	fin.seekg(0,std::ios_base::end);
	size_t size_fin = fin.tellg();
	fin.seekg(0,std::ios_base::beg);
	
	if (!fin) std::cout << "File not found!\n";
	
	char* file = new char[size_fin];
	fin.read(file,size_fin);
	
	std::cout << file << "\n";
	delete[] file;

	fin.seekg(0,std::ios_base::beg);
	std::cout << "Find: " << word << "\n";
	
	do{
		symbol = fin.get();

		if (word[index] == symbol){
			index++;
			
			if (index == (strlen(word))){
				std::cout << "The word is find!\n";
				break;
			}
		}
		else{
			index = 0;
			if (symbol == '\00') std::cout << "The word is not find!\n";
		}
	} while (symbol != '\00');
	
	fin.close();
	
	return 0;
}
