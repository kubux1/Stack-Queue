#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "FILO.cpp"
#include "FIFO.cpp"
#define length 25000
using namespace std;
FIFO fifo_element;
Stack filo_element;

void operations(char *text) {
	unsigned int i = 3, j = 0;
	int end = 0;
		char text_send[length];

	switch (text[0]) {

		//dodanie stringa do kolejki
	case 'a':
		if (text[2] != '\0') {
			while (text[i] != '\0') {
				text_send[j] = text[i];
				++i;
				++j;
			}
			text_send[j] = '\0';
			j = 0;
			if (text[1] == 'k') {
				fifo_element.push_back(text_send);
			}
			if (text[1] == 's') {
				filo_element.push(text_send);
			}
		}
		break;

		//usuwanie stringa z kolejki
	case 'd':
		if (text[1] == 'k') {
			fifo_element.pop_back();
		}
		if (text[1] == 's') {
			filo_element.pop();
		}
		break;

		//powielanie stringa do kolejki
	case 'c':
		if (text[1] == 'k') {
			if (text[2] == 'k') {
				if (fifo_element.copy())
					fifo_element.push_back(fifo_element.copy());
			}
			if (text[2] == 's') {
				if (fifo_element.copy())
					filo_element.push(fifo_element.copy());
			}
		}
		if (text[1] == 's') {
			if (text[2] == 'k') {
				if (filo_element.copy())	
					fifo_element.push_back(filo_element.copy());
			}
			if (text[2] == 's') {
				if (filo_element.copy())
					filo_element.push(filo_element.copy());
			}
		}
		break;

		//przenoszenie stringa
	case 'm':
		if (text[1] == 'k') {
			if (text[2] == 'k') {
				if (fifo_element.copy()) {
					fifo_element.push_back(fifo_element.copy());
					fifo_element.pop_back();
				}
			}
			if (text[2] == 's') {
				if (fifo_element.copy()) {
					filo_element.push(fifo_element.copy());
					fifo_element.pop_back();
				}
			}
		}

		if (text[1] == 's') {
			if (text[2] == 'k') {
				if (filo_element.copy()) {
					fifo_element.push_back(filo_element.copy());
					filo_element.pop();
				}
			}
			if (text[2] == 's') {
				if (fifo_element.copy()) {
					filo_element.push(filo_element.copy());
					filo_element.pop();
				}
			}
		}
		break;

		//laczenie stringow z kolejek
	case 'j':
		if (text[1] == 'k') {
			end = fifo_element.fill_array(text_send, end);
			if (filo_element.fill_array(text_send, end) != -2) {
				if (text[2] == 'k')
					fifo_element.push_back(text_send);
				if (text[2] == 's')
					filo_element.push(text_send);
			}
		}
		if (text[1] == 's') {
			end = filo_element.fill_array(text_send, end);
			if (fifo_element.fill_array(text_send, end) != -2) {
				if (text[2] == 'k')
					fifo_element.push_back(text_send);
				if (text[2] == 's')
					filo_element.push(text_send);
			}
		}
		break;

		//wyswietlanie kolejek
	case 's':
		if (text[1] == 'k') {
			fifo_element.show();
			cout << endl;
		}
		if (text[1] == 's') {
			filo_element.show();
			cout << endl;
		}
		break;
	}
}
int main() {
	char text[length];
	unsigned int how_many;
	cin >> how_many;
	getchar();
	for (unsigned int i = 0; i <= how_many; i++)
	{
		cin.getline(text, sizeof(text));
			operations(text);
	}


	return 0;
}