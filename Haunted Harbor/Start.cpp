#include "Start.h"

Start::Start() {
	button = new Button("button", 200, 300, 150, 75, 255, 30, 30);
}

bool Start::input(int x, int y, bool down) {
	return button->input(x, y, down);
}

void Start::render(HDC context) {
	//Create objects
	HBRUSH bg = CreateSolidBrush(RGB(0, 0, 0));
	LPCWSTR title = L"Haunted Harbour";
	RECT rect = { 25, 25, 610, 100 };

	//Bind objects
	SelectObject(context, bg);

	//Draw
	Rectangle(context, 0, 0, gsw, gsh);
	Rectangle(context, rect.left, rect.top, rect.right, rect.bottom);

	HFONT f = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	LOGFONT lf;
	GetObject(f, sizeof(lf), &lf);
	lf.lfHeight = 75;
	//other properties
	HFONT nf = CreateFontIndirect(&lf);
	HFONT of = (HFONT)SelectObject(context, nf);
	SetTextColor(context, COLORREF(RGB(255, 0, 0)));
	SetBkMode(context, TRANSPARENT);
	DrawText(context, title, -1, &rect, DT_SINGLELINE | DT_NOCLIP | DT_CENTER);
	SelectObject(context, of);

	button->draw(context);

	//Destroy
	DeleteObject(bg);
}