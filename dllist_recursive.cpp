#include <iostream>
/*extra 7 -"ANY DOUBLY LINKED LIST WITH COUNTNODE RECURSIVELY, PRINT BACKWARD, FORWARD"
 *Arya HajiTaheri
 *1518105
 */
struct node {
	int data;
	node *next, *prev;

};
class dllist_recursive {
	node *head, *tail;
public:
	dllist_recursive();
	~dllist_recursive();
	void createnode(int);
	void print_fow_rec(node *);
	void print_bac_rec(node *);
	int countnode(node *);
	node *gethead();
	node *gettail();

};
dllist_recursive::dllist_recursive() {
	head = NULL;
	tail = NULL;
}
dllist_recursive::~dllist_recursive() {
}
node *dllist_recursive::gethead() {
	return head;
}
node *dllist_recursive::gettail() {
	return tail;
}
void dllist_recursive::createnode(int value) {
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL) {
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}
void dllist_recursive::print_fow_rec(node *h) {
	if (h == head) {
		std::cout << "printing forward:\n";
		std::cout << "NULL<-";
	}if (h->next == NULL) {
		std::cout << h->data << "->NULL";
	}else if (h != NULL) {
		std::cout << h->data << "<->";
		print_fow_rec(h->next);
	}
}
void dllist_recursive::print_bac_rec(node *h) {
	if (h == tail) {
		std::cout << "\nprinting backward:\n";
		std::cout << "NULL<-";
	}if (h->prev == NULL) {
		std::cout << h->data << "->NULL";
	}else if (h != NULL) {
		std::cout << h->data << "<->";
		print_bac_rec(h->prev);
	}
}
int dllist_recursive::countnode(node *c) {
	if (c == head) {std::cout << "\nNumber of elements:";}
	if (head == NULL) { std::cout << "Empty list\n"; return 0; }
	if (c->next == NULL) { return 1; }
	return 1 + countnode(c->next);
}

int main(int argc, char * argv[]) {
	dllist_recursive element;

	for (int i = 0; i < 10; i++) {
		element.createnode(i);
	}
	element.print_fow_rec(element.gethead());
	element.print_bac_rec(element.gettail());
	std::cout << element.countnode(element.gethead())<<"\n";

	return 0;
}