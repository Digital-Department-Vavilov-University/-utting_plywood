#include "MyForm.h"

using namespace System::Windows::Forms; // Добавляем пространство имен

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles(); // Теперь Application - это класс из System::Windows::Forms
    Application::SetCompatibleTextRenderingDefault(false); // То же самое здесь
    Application::Run(gcnew MyForm); // И здесь
    return 0;
}