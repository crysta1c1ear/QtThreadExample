#include "generator.h"

Generator::Generator(QObject* parent)
{
    connect(this, SIGNAL(finished()), parent, SLOT(onGeneratorFinished()));
}

void Generator::run()
{
}
