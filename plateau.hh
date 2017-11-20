class Plateau {
	private:
		int size;
		Objet** tableau;

		void createTableau() {
			this->tableau = new Objet*[size];
			for(unsigned int i = 0; i < size; ++i) {
				this->tableau[i] = new Objet[size];
			}
		}

		
	public:
		// Plateau without data.txt
		Plateau(int size = 8) {
			this->size = size;		
			createTableau();
		}
		// Plateau with data.txt
		Plateau(std::string filepath) {
			this->size = getLengthFile(filepath);
			createTableau();

			unsigned int i = 0;
			unsigned int j = 0;
			char ch;
			std::fstream fin(filepath, std::fstream::in);
			while (fin >> std::noskipws >> ch) {
				
			}
		}
		~Plateau();
	
		int getLengthFile(std::string filepath) {
			std::ifstream file(filepath);
			std::string str;
			std::getline(file, str);
			return str.length();
		}

		void draw() {
			std::string = "";
			for (int i = 0; i < this.size; ++i) {
				for (int j = 0; j < this.size; ++j) {
					string += tableau[i][j].getSymbole();
				}
				string += "\n";
			}
			std::cout << string << std::endl;
		}
};
