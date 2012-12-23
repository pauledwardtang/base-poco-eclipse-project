
#include <iostream>
#include <fstream>

#include "Poco/DOM/DOMParser.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/NodeIterator.h"
#include "Poco/DOM/NodeFilter.h"
#include "Poco/DOM/AutoPtr.h"
#include "Poco/SAX/InputSource.h"

int main()
{
    std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

    try
    {
        std::ifstream in("resources/test.xml");
        Poco::XML::InputSource src(in);
        Poco::XML::DOMParser parser;
        Poco::AutoPtr<Poco::XML::Document> pDoc = parser.parse(&src);

        Poco::XML::NodeIterator it(pDoc, Poco::XML::NodeFilter::SHOW_ELEMENT);
        Poco::XML::Node* pNode = it.nextNode();
        while (pNode)
        {
         std::cout<<pNode->nodeName()<<":"<< pNode->nodeValue()<<std::endl;
         pNode = it.nextNode();
        }
    }
    catch(Poco::Exception& ex)
    {
        std::cout << ex.message();
    }

    return 0;
}
