<?hh // strict

namespace Diff\Generator;

use HackPack\HackUnit\Core\Expectation;
use HackPack\HackUnit\Core\TestCase;

class GenericTest extends TestCase
{
    public function testOutputsDiff(): void
    {
        $expected = "-from\n+to\n";
        $typeDiffer = new Generic("from", "to");
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }
}
