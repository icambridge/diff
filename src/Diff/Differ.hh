<?hh //strict

namespace Diff;

class Differ
{
    public function __construct(private string $header = "--- Original\n+++ New\n") {}

    public function diff(mixed $expected, mixed $actual): string
    {
        $generator = $this->generator($expected, $actual);
        $message = $generator->diff();


        return $this->header . "@@ @@\n" . $message;
    }

    private function generator(mixed $expected, mixed $actual): Generator\Generator
    {
        $expectedType = gettype($expected);

        if (gettype($actual) != $expectedType) {
            return new Generator\Mismatch($expected, $actual);
        } elseif("array" == $expectedType) {
            return new Generator\Arrays($expected, $actual);
        } else {
            return new Generator\Generic($expected, $actual);
        }
    }

}
