#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define length 25000
using namespace std;

class FIFO_Element {
	friend class FIFO;
	char text[length];
	FIFO_Element *next;

	// inicjalizacja tablicy char danego obiektu napisem z konsoli
	FIFO_Element(char text_oryg[length]) {
		if (text_oryg != NULL) {

			unsigned int i = 0;
			while (text_oryg[i] != '\0') {
				text[i] = text_oryg[i];
				i++;
			}
			text[i] = '\0';
			i = 0;
		}
	}
};

class FIFO {
	FIFO_Element *tail;
	FIFO_Element *head;
	char text[length];
public:

	FIFO() { tail = nullptr; head = nullptr; }
	//dodawanie elementu
	void push_back(char text_oryg[length]) {
		if (text_oryg != NULL) {
			FIFO_Element *newEl = new FIFO_Element(text_oryg);
			newEl->next = NULL;
			if (head == NULL)
				head = newEl;
			else {
				tail->next = newEl;
			}
			tail = newEl;
		}
	}

	//usuwanie elmentu
	char* pop_back() {
		if (head == NULL) {

			return 0;
		}
		else {
			FIFO_Element *tmp = head;

			strncpy(text, head->text, sizeof(head->text));

			head = head->next;

			delete(tmp);
			return text;
		}
	}

	int fill_array(char text_send[length], int end) {
		if (head->text != NULL && end != -2) {
			int i = 0;
			while (head->text[i] != '\0')
			{
				text_send[end] = head->text[i];
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
		if (head->text != NULL)
			return head->text;
		else return 0;
	}

	//wyswietlanie elementu
	void show() {
		if (head == NULL)
			cout << '#';
		else
			cout << head->text;
	}

};