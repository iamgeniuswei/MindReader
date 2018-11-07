#include <QCoreApplication>
#include "mupdf/fitz.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fz_context *context = fz_new_context (nullptr, nullptr, FZ_STORE_UNLIMITED);
    fz_register_document_handlers (context);
    fz_document *doc = fz_open_document (context, "D:/Article/56.pdf");
    fz_drop_document (context, doc);
    qDebug() << context->error->top;
    qDebug() <<( context->error->stack -1 );
    assert (context->error->top == context->error->stack-1);
    fz_drop_context (context);
    return a.exec();
}
