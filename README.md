# system.net

Partial c++ implementation of .NET System.Net classes 

## Example Hello World

```c++
#include <system.net/httplistener.h>
#include <system.net/httplistenerexception.h>
#include <iostream>

using namespace System::Net::Http;

int main(int argc, char* argv[])
{
    HttpListener listener;

    listener.Prefixes().push_back("http://localhost:8383/");

    try
    {
        listener.Start();

        auto context = listener.GetContext();

        context->Response()->WriteResponse("<html><body><h1>Hello world</h1></body</html>");
        context->Response()->Close();
        
        delete context;

        listener.Stop();
    }
    catch (HttpListenerException const *ex)
    {
        std::cout << "Exception in http listener: " << ex->Message() << "\n";
    }

    return 0;
}

```

## Example Redirect

```c++
#include <system.net/httplistener.h>
#include <system.net/httplistenerexception.h>
#include <iostream>

using namespace System::Net::Http;

int main(int argc, char* argv[])
{
    HttpListener listener;

    listener.Prefixes().push_back("http://localhost:8383/");

    try
    {
        listener.Start();

        auto context = listener.GetContext();

        context->Response()->Redirect("https://github.com/wtrsltnk");
        
        delete context;

        listener.Stop();
    }
    catch (HttpListenerException const *ex)
    {
        std::cout << "Exception in http listener: " << ex->Message() << "\n";
    }

    return 0;
}

```