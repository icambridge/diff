<?hh // strict

namespace Diff\Generator;

use HackPack\HackUnit\Core\Expectation;
use HackPack\HackUnit\Core\TestCase;

class MismatchTest extends TestCase
{
    public function testOutputsStringVsArray(): void
    {
        $expected = "-<string> string\n+<array>\n";
        $typeDiffer = new Mismatch("string", []);
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }

    public function testOutputsIntVsString(): void
    {
        $expected = "-<string> string\n+<integer> 1\n";
        $typeDiffer = new Mismatch("string", 1);
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }
}
