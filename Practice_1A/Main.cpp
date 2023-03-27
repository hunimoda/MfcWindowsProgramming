#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OutputTextAtCenter(HWND hWnd, LPCTSTR lpszOutString);
void OutputTextAt(HWND hWnd, LPCTSTR lpszOutString, POINT point);

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine, int nCmdShow) {
  // 윈도우 클래스 생성
  WNDCLASS wndClass = { 0, };
  // WNDCLASSEX wndClass = { 0, };
  // wndClass.cbSize = sizeof(wndClass);
  wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
  wndClass.lpfnWndProc = WndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = hInstance;
  wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wndClass.lpszMenuName = NULL;
  wndClass.lpszClassName = _T("EasyText");
  // wndClass.hIconSm = 0;

  // 윈도우 클래스 등록
  // RegisterClassEx(&wndClass);
  RegisterClass(&wndClass);

  // 프레임 윈도우 생성
  HWND hWnd = CreateWindow(
      _T("EasyText"), _T("Practice_1A"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
      NULL, NULL, hInstance, NULL);

  // 프레임 윈도우를 화면에 표시
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  // 메시지 큐로부터 메시지를 받아와 메시지를 해당 윈도우 프로시저로 전달
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}

LRESULT CALLBACK WndProc(
    HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  HDC hdc;
  RECT rect;
  PAINTSTRUCT ps;
  LPCTSTR msg1 = _T("I love Windows programming!");
  LPCTSTR msg2 = _T("키보드가 눌렸습니다.");
  LPCTSTR msg3 = _T("키보드를 뗐습니다.");
  TCHAR msg[64];
  POINT mousePoint;

  switch (message) {
    case WM_CREATE: break;
    case WM_PAINT:
      hdc = BeginPaint(hWnd, &ps);
      TextOut(hdc, 10, 10, msg1, _tcslen(msg1));
      EndPaint(hWnd, &ps);
      break;

    case WM_LBUTTONDOWN:
      mousePoint = { LOWORD(lParam), HIWORD(lParam) };
      _stprintf(msg, _T("[%d, %d]에 마우스 클릭!"), mousePoint.x, mousePoint.y);
      OutputTextAt(hWnd, msg, mousePoint);
      break;

    case WM_LBUTTONUP:
      InvalidateRect(hWnd, NULL, TRUE);
      break;

    case WM_MOUSEMOVE:
      OutputTextAtCenter(hWnd, _T("마우스가 움직입니다!"));
      break;

    // case WM_KEYDOWN:
    //   hdc = GetDC(hWnd);
    //   GetClientRect(hWnd, &rect);
    //   DrawText(hdc, msg2, _tcslen(msg2), &rect,
    //            DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    //   ReleaseDC(hWnd, hdc);
    //   break;

    // case WM_KEYUP:
    //   hdc = GetDC(hWnd);
    //   GetClientRect(hWnd, &rect);
    //   DrawText(hdc, msg3, _tcslen(msg3), &rect,
    //            DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    //   ReleaseDC(hWnd, hdc);
    //   break;

    // case WM_LBUTTONDBLCLK:
    //   MessageBox(hWnd, _T("마우스 더블 클릭!"), _T("마우스 메시지"),
    //              MB_OK | MB_ICONASTERISK);
    //   break;

    case WM_DESTROY:
      PostQuitMessage(0);
      break;

    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

void OutputTextAtCenter(HWND hWnd, LPCTSTR lpszOutString) {
  HDC hdc = GetDC(hWnd);
  RECT rect;
  GetClientRect(hWnd, &rect);
  DrawText(hdc, lpszOutString, _tcslen(lpszOutString), &rect,
           DT_SINGLELINE | DT_CENTER | DT_VCENTER);
  ReleaseDC(hWnd, hdc);
}

void OutputTextAt(HWND hWnd, LPCTSTR lpszOutString, POINT point) {
  HDC hdc = GetDC(hWnd);
  TextOut(hdc, point.x, point.y, lpszOutString, _tcslen(lpszOutString));
  ReleaseDC(hWnd, hdc);
}
