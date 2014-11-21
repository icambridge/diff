<?hh // strict

namespace Diff\Generator;

interface Generator
{
    public function diff(): string;
}
