#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define length 25000
using namespace std;

class Stack_Element {

	friend class Stack;

	char text[length]; // zrobic dynamiczna tablice przy wczytywaniu
	Stack_Element *previous;

	// inicjalizacja tablicy char danego obiektu napisem z konsoli
	Stack_Element(char text_oryg[length]) {
		previous = NULL;
		if (text_oryg != NULL) {
			int i = 0;
			while (text_oryg[i] != '\0') {
				text[i] = text_oryg[i];
				i++;
			}
			text[i] = '\0';
			i = 0;
		}
	}
};

class Stack {
	Stack_Element *top;
public:

	char text[length];
	Stack() { top = NULL; }
	//dodawanie elementu
	void push(char text_oryg[length]) {
		if (text_oryg != NULL) {
			Stack_Element *newEl = new  Stack_Element(text_oryg);
			newEl->previous = NULL;
			if (top != NULL)
				newEl->previous = top;
			top = newEl;
		}
	}

	//usuwanie elmentu
	char* pop() {
		if (top == NULL) {

			return 0;
		}
		else {
			Stack_Element *tmp = top;

			strncpy(text, top->text, sizeof(top->text));

			top = top->previous;
			delete(tmp);
			return text;
		}
	}

	int fill_array(char text_send[length], int end) {
		if (top->text != NULL && end != -2) {
			int i = 0;
			while (top->text[i] != '\0')
			{
				text_send[end] = top->text[i];
				++end;
				++i;
			}
			i = 0;
			text_send[end] = '\0';
			return end;
		}
		else return -2;
	}

	//powielanie elementu
	char* copy() {
		if (top->text != NULL)
			return top->text;
		else return 0;
	}

	//wyswietlanie elementu
	void show() {
		if (top == NULL)
			cout << '#';
		else
			cout << top->text;
	}

};