<?hh //strict

namespace Diff\Generator;

use HackPack\HackUnit\Core\Expectation;
use HackPack\HackUnit\Core\TestCase;

class VectorsTest extends TestCase
{
    public function testOneItemBothDifferent(): void
    {
        $expected = "-hello\n+world\n";
        $typeDiffer = new Vectors(Vector{"hello"}, Vector{"world"});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }

    public function testTwoItemsFirstDifferent(): void
    {
        $expected = "-1\n+2\n 2\n";
        $typeDiffer = new Vectors(Vector{1,2}, Vector{2,2});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }

    public function testThreeItemsFirstDifferentLastDifferent(): void
    {
        $expected = "-1\n+2\n 2\n-3\n+4\n";
        $typeDiffer = new Vectors(Vector{1,2,3}, Vector{2,2,4});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }

    public function testJustLastDifferent(): void
    {
        $expected = " 1\n 2\n-3\n+4\n";
        $typeDiffer = new Vectors(Vector{1,2,3}, Vector{1,2,4});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }

    public function testExtraOnTheEnd(): void
    {
        $expected = " 1\n 2\n-3\n+4\n+5\n+6\n+7\n";
        $typeDiffer = new Vectors(Vector{1,2,3}, Vector{1,2,4,5,6,7});
        $actual = $typeDiffer->diff();
        $this->expect($actual)->toEqual($expected);
    }
}
