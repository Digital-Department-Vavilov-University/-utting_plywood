#include "MyForm.h"

using namespace System::Windows::Forms; // ��������� ������������ ����

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles(); // ������ Application - ��� ����� �� System::Windows::Forms
    Application::SetCompatibleTextRenderingDefault(false); // �� �� ����� �����
    Application::Run(gcnew MyForm); // � �����
    return 0;
}