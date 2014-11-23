<?hh //strict

namespace Diff;

use HackPack\HackUnit\Core\Expectation;
use HackPack\HackUnit\Core\TestCase;

class DifferTest extends TestCase
{
    public function testDiffReturnsStringOutput(): void
    {
        $expected = "--- Original\n+++ New\n@@ @@\n-bc\n+abc\n";
        $differ = new Differ();
        $actual = $differ->diff("bc", "abc");
        $this->expect($actual)->toEqual($expected);
    }

    public function testDiffReturnsDifferentHeader(): void
    {
        $customHeader = "--- Expected\n+++ Actual\n";
        $expected = $customHeader."@@ @@\n-bc\n+abc\n";

        $differ = new Differ($customHeader);
        $actual = $differ->diff("bc", "abc");
        $this->expect($actual)->toEqual($expected);
    }

    public function testDifFMapps(): void
    {
        $customHeader = "--- Expected\n+++ Actual\n";
        $expected = $customHeader."@@ @@\n hello => world\n-start => finish\n+start => n\n";

        $differ = new Differ($customHeader);
        $actual = $differ->diff(
            Map {"hello" => "world", "start" => "finish"},
            Map {"hello" => "world", "start" => "n"}
        );
        $this->expect($actual)->toEqual($expected);
    }
}
