#include "Views/LoginForm.h"
#include "Views/MainMenu.h"
#include "Views/CustomerForm.h"
#include "Utils/GlobalVariables.h"
#include "Managers/UserForm.h"

using namespace std;
using namespace SupermarketManagement;

[STAThreadAttribute] int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    LoginForm ^ userLogin = gcnew LoginForm();
    MainMenu ^ homeMenu = gcnew MainMenu();
    CustomerForm ^ clientsMenu = gcnew CustomerForm();
    UserForm ^ usersMenu = gcnew UserForm();

    Application::Run(userLogin);

    return 0;
}