#include "JoueurReel.h"


Point JoueurReel::getPoint() {
	cout << "Inserez le point a attaquer" << endl;
	int x, y;
	do
    {
		cout << "coordonnee en x : ";
		cin >> x;
	} while ( (x < 0) || (x > 9) );
    
	do
    {
		cout << "coordonnee en y : ";
		cin >> y;
	} while ((y < 0) || (y > 9));

	return Point(x, y);
}

bool JoueurReel::attaquer(Joueur* j) {
	Point p = getPoint();
	while (dejaTeste(p)) {
        cout << "Point deja teste, reessayez" << endl;
			p = getPoint();
	}
	getDejaTeste().push_back(p);
	return j->detruire(p);
}
