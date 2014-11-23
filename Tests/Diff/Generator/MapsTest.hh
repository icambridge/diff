<?hh //strict

namespace Diff\Generator;

use HackPack\HackUnit\Core\Expectation;
use HackPack\HackUnit\Core\TestCase;

class MapsTest extends TestCase
{
    public function testOneItemBothDifferent(): void
    {
        $expected = "-hello => world\n+hello => universe\n";
        $typeDiffer = new Maps(Map {"hello" => "world"}, Map {"hello" => "universe"});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }

    public function testFirstItemSameSecondItemDifferent(): void
    {
        $expected = " hello => world\n-start => finish\n+start => n\n";
        $typeDiffer = new Maps(Map {"hello" => "world", "start" => "finish"}, Map {"hello" => "world", "start" => "n"});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }
}
