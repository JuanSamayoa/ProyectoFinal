#include "UserLogin.h"
#include "HomeMenu.h"
#include "Clients.h"
#include "GlobalVariables.h"
#include "Users.h"

using namespace std;
using namespace ProyectoFinal;


int main() {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    UserLogin^ userLogin = gcnew UserLogin();
    HomeMenu^ homeMenu = gcnew HomeMenu();
    Clients^ clientsMenu = gcnew Clients();
    Users^ usersMenu = gcnew Users();

    Application::Run(userLogin);

    return 0;
}